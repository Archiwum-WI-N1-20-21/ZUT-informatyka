form Give the parameters for pause analysis
   comment This script marks the pauses in the LongSound to the IntervalTier of the TextGrid.
   comment Give the time period you wish to include (The TextGrid will be overwritten!):
   real Starting_time_(seconds) 0
   real Finishing_time_(0=all) 0
   comment The following criteria define a pause:
   positive Minimum_duration_(seconds) 0.6
   positive Maximum_intensity_(dB) 59
   comment Give the intensity analysis parameters:
	 positive Minimum_pitch_(Hz) 100
	 integer Time_step_(0=auto) 0
   comment Give the window size for the intensity analyses (smaller window requires less memory):
	 positive Window_size_(seconds) 20
	 choice Boundary_placement 2
	button One boundary at the center of each pause
	button Two boundaries with a time margin of:
	positive Margin_(seconds) 0.1
   comment Save TextGrid file to folder:
	text folder C:\Users\baraomar\Desktop\
   comment The script will pause after calculating 4 windows, so you can interrupt the script and check if the pause detection works optimally.
endform


soundname$ = selected$ ("LongSound")
To TextGrid... sentence 

if fileReadable ("'folder$''soundname$'.TextGrid")
	pause The file 'folder$''soundname$'.TextGrid already exists. Do you want to overwrite it?
endif

select TextGrid 'soundname$'
	endofsound = Get finishing time
select LongSound 'soundname$'
	pausenumber = 0
	duration = 0
	count = 0
	loops = 0
	pauses_found = 0
	windowstart = 0
	windowend = 0
	frame = 0
	frames = 0
	time = 0
	intensity = 0
	pausedetected = 0
	pausestart = 0
	pauseend = 0
	pausenumber = 0
	halfpause = 0
# This form prompts for parameters for the pause analysis:
if finishing_time < 0
exit Finishing time must be greater than or equal to zero! (If you give a zero, the whole LongSound will be analysed.)
endif
if finishing_time = 0
finishing_time = endofsound
endif
#******************************************************************************************************
# BEGIN
#******************************************************************************************************
# DIVIDE LONGSOUND INTO SHORTER PERIODS AND LOOP THROUGH EACH
duration = finishing_time - starting_time
#--------------------------------------------------------------------------------------------------
# Default number of loops is 1
loops = 1
# but if the period to be analysed is longer than 60 seconds, it will be divided into 60-second
# periods for which the analysis is made:
if duration > window_size
loops = ceiling ((duration/window_size))
endif
#--------------------------------------------------------------------------------------------------
# START LOOPING THROUGH SHORT WINDOWS HERE
count = 1
latest_endboundary = 0
while count <= loops
	if count = 5
		pause Continue?
	endif
	# Create a window of the LongSound and extract it for analysis
	windowstart = starting_time + ((count - 1) * window_size)
	windowend = starting_time + (count * window_size)
	if windowend > endofsound
	windowend = endofsound
	endif
	if windowend > finishing_time
	windowend = finishing_time
	endif
	select LongSound 'soundname$'
	Extract part... windowstart windowend yes
	windowname$ = "Window_" + "'count'" + "_of_" + "'loops'"
	echo Analysing Intensity window 'count' of 'loops'
	if count < 5
		printline The script will pause after calculating 4 windows, so you can check the result...
	endif
	Rename... 'windowname$'
	#--------------------------------------------------------------------------------------------------
	# CALCULATE INTENSITY
	To Intensity... minimum_pitch time_step
	frames = Get number of frames
	#--------------------------------------------------------------------------------------------------
	# Check the pause criteria
	pauseend = 0
	frame = 1
		#--------------------------------------------------------------------------------------------------
		# Loop through all frames in the Intensity object:
		while frame <= frames
			select Intensity 'windowname$'
			intensity = Get value in frame... frame
			time = Get time from frame... frame
				if intensity > maximum_intensity
					# If the end of an earlier detected possible pause has been reached:
					if pausedetected = 1
						if frame - 1 < 1
						pauseend = windowstart
						else
						pauseend = Get time from frame... (frame - 1)
						endif
						pausedetected = 0
					endif
				    # If below intensity limit, a possible new pause is started if one hasn't been detected yet:
				    elsif pausedetected = 0
						pausestart = Get time from frame... frame
						pauseend = 0
						pausedetected = 1
						pausenumber = pausenumber + 1
				# If a detected pause just continues, do nothing special.
				endif
			#--------------------------------------------------------------------------------------------------
			# IF PAUSE CRITERIA ARE FULFILLED, ADD A BOUNDARY OR TWO TO TEXTGRID
			if pauseend > 0
				pauseduration = pauseend - pausestart
				if pauseduration >= minimum_duration
					select TextGrid 'soundname$'
					halfpause = pauseduration / 2
						if boundary_placement = 1
							boundary = pausestart + halfpause
							call BoundaryCheck
							if boundaryexists = 0
								Insert boundary... 1 boundary
								latest_endboundary = boundary
							endif
						else
							boundary = 0
							if pauseduration >= (2 * margin)
								if pausestart > margin
									boundary = pausestart + margin
									call BoundaryCheck
									if boundaryexists = 0 and boundary > latest_endboundary
										Insert boundary... 1 boundary
									endif
									#If the pause overlaps with the preceding pause, do a merge:
									if boundary = latest_endboundary
										Remove boundary at time... 1 boundary
									endif
								endif
									pauseinterval = Get interval at time... 1 boundary
									Set interval text... 1 pauseinterval s
								endif
								boundary = pauseend - margin
								call BoundaryCheck
								if boundaryexists = 0 and boundary > latest_endboundary
									Insert boundary... 1 boundary
									latest_endboundary = boundary
								endif
							else
								if pauseend < (endofsound - margin)
									boundary = pausestart + halfpause
									call BoundaryCheck
									if boundaryexists = 0 and boundary > latest_endboundary
										Insert boundary... 1 boundary
										latest_endboundary = boundary
									endif
								endif
							endif
						endif
					pauseend = 0
					pauses_found = pauses_found + 1
					Write to text file... 'folder$''soundname$'.TextGrid
				endif
			endif
			frame = frame + 1
			# When all frames in the intensity analysis have been looked at, end the frame loop.
		endwhile
		#--------------------------------------------------------------------------------------------------
	select Sound 'windowname$'
	Remove
	select Intensity 'windowname$'
	Remove
	# END LOOPING THROUGH WINDOWS HERE
	count = count + 1
endwhile

select TextGrid 'soundname$'

numint = Get number of intervals... 1
	for i from 1 to numint
		select TextGrid 'soundname$'
		str$ = Get label of interval... 1 i 
		if str$ <> "s"
			Set interval text... 1 i v
		endif
	endfor

Write to text file... 'folder$''soundname$'.TextGrid

echo Ready! The TextGrid file was saved as 'folder$''soundname$'.TextGrid.

#******************************************************************************************************

procedure BoundaryCheck
# This procedure checks whether a boundary already exists at a given time (in tier 1).
# Added 23.1.2006
	tmpint = Get interval at time... 1 boundary
	tmpstart = Get starting point... 1 tmpint
	if tmpstart <> boundary
		boundaryexists = 0
	else
		boundaryexists = 1
	endif
endproc