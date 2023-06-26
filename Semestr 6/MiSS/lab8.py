from dataclasses import dataclass
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import colors
import imageio.v2 as imageio
import random
import os

# Set numpy print options
np.set_printoptions(threshold=np.inf)

# Color map for plotting
cmap = colors.ListedColormap(['white', 'green', 'orange', 'red', 'yellow'])
bounds = [0, 1, 2, 3, 4]
norm = colors.BoundaryNorm(bounds, cmap.N)

# Struct for population
@dataclass
class Person:
	id: int
	speed: int
	direction: str
	state: str
	daysInState: int
	age: int
	immunity: float

def generatePopulation(population, map):
	id = len(population) + 1
	speed = random.randint(1, 3)
	direction = random.choice(['N', 'NE', 'E', 'SE', 'S', 'SW', 'W', 'NW'])
	state = random.choice(['Z', 'C', 'ZD', 'ZZ'])
	daysInState = 0
	age = random.randint(0, 100)
	immunity = 0
	# Low immunity for children and old people
	if 15 > age or age >= 70:
		immunity = round(random.uniform(0.05, 3), 2)
	# Medium immunity for adults
	elif 40 <= age < 70:
		immunity = round(random.uniform(3.05, 6), 2)
	# High immunity for young adults
	elif 15 <= age < 40:
		immunity = round(random.uniform(6.05, 10), 2)
	person = Person(id, speed, direction, state, daysInState, age, immunity)

	X = random.randint(0, 99)
	Y = random.randint(0, 99)
	while map[X][Y] != 0:
		X = random.randint(0, 99)
		Y = random.randint(0, 99)
	
	map[X][Y] = id

	population.append(person)

	return population, map

def calculateImmunity(population):
	deaths = []

	# Calculate immunity
	for person in population:
		if person.state == 'Z':
			person.immunity -= 0.1
			if checkKill(person):
				deaths.append(person.id) 
			continue
		if person.state == 'C':
			person.immunity -= 0.5
			if checkKill(person):
				deaths.append(person.id) 
			continue
		if person.state == 'ZD':
			person.immunity += 0.1
			person = checkImmunityCap(person)
			continue
		if person.state == 'ZZ':
			person.immunity += 0.5
			person = checkImmunityCap(person)
			continue

	# Remove dead people
	for i in deaths:
		for person in population:
			if person.id == i:
				population.remove(person)
				
				# Remove from map
				for k in range(100):
					for l in range(100):
						if map[k][l] == i:
							map[k][l] = 0
							break
				break

	return population

def calculateMove(population, map):
	# Could be improved, when person cannot move due to occupied spot or map end, it changes direction and moves next day
	# Better approach would be to move with a lower speed and change direction only when there is direct contact
	# If indexError happens it means that person is on the edge of the map and should change direction
	moved = False

	for person in population:
		for i in range(100):
			if moved:
				moved = False
				break
			for j in range(100):
				if map[i][j] == person.id:
					if person.direction == 'N':
						try:
							if map[i - person.speed][j] == 0:
								map[i][j] = 0
								map[i - person.speed][j] = person.id
							else:
								person.direction = random.choice(['NE', 'E', 'SE', 'S', 'SW', 'W', 'NW'])
						except IndexError:
							person.direction = random.choice(['NE', 'E', 'SE', 'S', 'SW', 'W', 'NW'])
						
						moved = True
						break
					elif person.direction == 'NE':
						try:
							if map[i - person.speed][j + person.speed] == 0:
								map[i][j] = 0
								map[i - person.speed][j + person.speed] = person.id
							else:
								person.direction = random.choice(['N', 'E', 'SE', 'S', 'SW', 'W', 'NW'])
						except IndexError:
							person.direction = random.choice(['N', 'E', 'SE', 'S', 'SW', 'W', 'NW'])

						moved = True
						break
					elif person.direction == 'E':
						try:
							if map[i][j + person.speed] == 0:
								map[i][j] = 0
								map[i][j + person.speed] = person.id
							else:
								person.direction = random.choice(['N', 'NE', 'SE', 'S', 'SW', 'W', 'NW'])
						except IndexError:
							person.direction = random.choice(['N', 'NE', 'SE', 'S', 'SW', 'W', 'NW'])

						moved = True
						break
					elif person.direction == 'SE':
						try:
							if map[i + person.speed][j + person.speed] == 0:
								map[i][j] = 0
								map[i + person.speed][j + person.speed] = person.id
							else:
								person.direction = random.choice(['N', 'NE', 'E', 'S', 'SW', 'W', 'NW'])
						except IndexError:
							person.direction = random.choice(['N', 'NE', 'E', 'S', 'SW', 'W', 'NW'])

						moved = True
						break
					elif person.direction == 'S':
						try:
							if map[i + person.speed][j] == 0:
								map[i][j] = 0
								map[i + person.speed][j] = person.id
							else:
								person.direction = random.choice(['N', 'NE', 'E', 'SE', 'SW', 'W', 'NW'])
						except IndexError:
							person.direction = random.choice(['N', 'NE', 'E', 'SE', 'SW', 'W', 'NW'])

						moved = True
						break
					elif person.direction == 'SW':
						try:
							if map[i + person.speed][j - person.speed] == 0:
								map[i][j] = 0
								map[i + person.speed][j - person.speed] = person.id
							else:
								person.direction = random.choice(['N', 'NE', 'E', 'SE', 'S', 'W', 'NW'])
						except IndexError:
							person.direction = random.choice(['N', 'NE', 'E', 'SE', 'S', 'W', 'NW'])
						
						moved = True
						break
					elif person.direction == 'W':
						try:
							if map[i][j - person.speed] == 0:
								map[i][j] = 0
								map[i][j - person.speed] = person.id
							else:
								person.direction = random.choice(['N', 'NE', 'E', 'SE', 'S', 'SW', 'NW'])
						except IndexError:
							person.direction = random.choice(['N', 'NE', 'E', 'SE', 'S', 'SW', 'NW'])
						
						moved = True
						break
					elif person.direction == 'NW':
						try:
							if map[i - person.speed][j - person.speed] == 0:
								map[i][j] = 0
								map[i - person.speed][j - person.speed] = person.id
							else:
								person.direction = random.choice(['N', 'NE', 'E', 'SE', 'S', 'SW', 'W'])
						except IndexError:
							person.direction = random.choice(['N', 'NE', 'E', 'SE', 'S', 'SW', 'W'])
						
						moved = True
						break
					break

	return population, map

def calculateContact(population, map):
	# TODO maybe removing dead people from population list wasn't the best idea
	# Now I have to itereate over the population twice instead of just addresing the index
	for person in population:
		for i in range(100):
			for j in range(100):
				if map[i][j] == person.id:
					# Since instruction says that distance should only be checked in x or y axis I don't check diagonals
					for x in range(-2, 2):
						try:
							if map[i + x][j] != 0:
								for p in population:
									if p.id == map[i + x][j]:
										if person.state == 'ZZ':
											# Contacted person goes Z if low immunity
											if p.state == 'Z':
												if 0 < person.immunity <= 3:
													person.state = 'Z'
											
											# Contacted person goes Z if low or average immunity
											if p.state == 'C':
												if 0 < person.immunity <= 6:
													person.state = 'Z'
												# Contacted person loses 3 immunity if high immunity
												elif person.immunity >= 6.05:
													person.immunity -= 3
											
											# Contacted person gets +1 immunity
											if p.state == 'ZD':
												p.immunity += 1
											
											# Both people go to higer immunnity range or max for their age
											if p.state == 'ZZ':
												if 0 < person.immunity <= 3:
													person.immunity = 3
												elif 3 < person.immunity <= 6:
													person.immunity = 6
												person = checkImmunityCap(person)
												if 0 < p.immunity <= 3:
													p.immunity = 3
												elif 3 < p.immunity <= 6:
													p.immunity = 6
												p = checkImmunityCap(p)

										if person.state == 'C':
											# Contacting person zeroes out days in state
											# Contacted person goes C if low or average immunity
											if p.state == 'Z':
												if 0 < p.immunity <= 6:
													p.state = 'C'
												person.daysInState = 0

											# Contacted person goes Z if low or average immunity
											if p.state == 'ZD':
												if 0 < p.immunity <= 6:
													p.state = 'Z'

											# Both people go to lower immunity range and zero out days in state
											if p.state == 'C':
												if 3 < person.immunity <= 6:
													person.immunity = 3
												elif person.immunity >= 6:
													person.immunity = 6
												person.daysInState = 0
												if 3 < p.immunity <= 6:
													p.immunity = 3
												elif p.immunity >= 6:
													p.immunity = 6
												p.daysInState = 0
												
										if person.state == 'Z':
											# Contacted person loses 1 immunity
											if p.state == 'ZD':
												p.immunity -= 1

											# Both people lose 1 immunity
											if p.state == 'Z':
												person.immunity -= 1
												p.immunity -= 1
						except IndexError:
							continue

					for y in range(-2, 2):
						try:
							if map[i][j + y] != 0:
								for p in population:
									if p.id == map[i][j + y]:
										if person.state == 'ZZ':
											# Contacted person goes Z if low immunity
											if p.state == 'Z':
												if 0 < person.immunity <= 3:
													person.state = 'Z'
											
											# Contacted person goes Z if low or average immunity
											if p.state == 'C':
												if 0 < person.immunity <= 6:
													person.state = 'Z'
												# Contacted person loses 3 immunity if high immunity
												elif person.immunity >= 6.05:
													person.immunity -= 3
											
											# Contacted person gets +1 immunity
											if p.state == 'ZD':
												p.immunity += 1
											
											# Both people go to higer immunnity range or max for their age
											if p.state == 'ZZ':
												if 0 < person.immunity <= 3:
													person.immunity = 3
												elif 3 < person.immunity <= 6:
													person.immunity = 6
												person = checkImmunityCap(person)
												if 0 < p.immunity <= 3:
													p.immunity = 3
												elif 3 < p.immunity <= 6:
													p.immunity = 6
												p = checkImmunityCap(p)

										if person.state == 'C':
											# Contacting person zeroes out days in state
											# Contacted person goes C if low or average immunity
											if p.state == 'Z':
												if 0 < p.immunity <= 6:
													p.state = 'C'
												person.daysInState = 0

											# Contacted person goes Z if low or average immunity
											if p.state == 'ZD':
												if 0 < p.immunity <= 6:
													p.state = 'Z'

											# Both people go to lower immunity range and zero out days in state
											if p.state == 'C':
												if 3 < person.immunity <= 6:
													person.immunity = 3
												elif person.immunity >= 6:
													person.immunity = 6
												person.daysInState = 0
												if 3 < p.immunity <= 6:
													p.immunity = 3
												elif p.immunity >= 6:
													p.immunity = 6
												p.daysInState = 0
												
										if person.state == 'Z':
											# Contacted person loses 1 immunity
											if p.state == 'ZD':
												p.immunity -= 1

											# Both people lose 1 immunity
											if p.state == 'Z':
												person.immunity -= 1
												p.immunity -= 1
						except IndexError:
							continue	

	return population

def calculateState(population):
	for person in population:
		if person.state == 'Z':
			if person.daysInState == 2:
				person.state = 'C'
		if person.state == 'C':
			if person.daysInState == 7:
				person.state = 'ZD'
		if person.state == 'ZD':
			if person.daysInState == 5:
				person.state = 'ZZ'

	return population

def incrementDaysInState(population):
	for person in population:
		person.daysInState += 1

	return population
	
def checkKill(person):
	if person.immunity <= 0:
		return True

def checkImmunityCap(person):
	if 15 > person.age or person.age >= 70:
		if person.immunity > 3:
			person.immunity = 3
	elif 15 <= person.age < 40:
		if person.immunity > 10:
			person.immunity = 10
	elif 40 <= person.age < 70:
		if person.immunity > 6:
			person.immunity = 6

	return person

def plotMap(population, map, day):
	# Convert map to different values for plotting
	# Not the most optimal solution, but I don't have time to think of something better
	# It's needed to have values and not IDs to use colors map
	virusDefeated = False

	plotArray = np.zeros(shape=(100, 100))
	amounts = [0, 0, 0, 0]
	for i in range(100):
		for j in range(100):
			if map[i][j] != 0:
				for person in population: # Again, it was stupid to remove dead people from population
					if person.id == map[i][j]:
						if person.state == 'ZZ':
							plotArray[i][j] = 1
							amounts[0] += 1
							break
						elif person.state == 'ZD':
							plotArray[i][j] = 2
							amounts[1] += 1
							break
						elif person.state == 'C':
							plotArray[i][j] = 3
							amounts[2] += 1
							break
						elif person.state == 'Z':
							plotArray[i][j] = 4
							amounts[3] += 1
							break

	plt.imshow(plotArray, interpolation='nearest', origin='lower', cmap=cmap, norm=norm)
	plt.title(label="Dzien: {}".format(day))
	plt.annotate("Populacja: {}\n\nZdrowi: {}\nZdrowiejacy: {}\nChorzy: {}\nZarazeni: {}".format(len(population), amounts[0], amounts[1], amounts[2], amounts[3]), xy=(100, 50), annotation_clip=False)
	if not os.path.exists("{}/plots".format(os.path.realpath(os.path.dirname(__file__)))):
		os.makedirs("{}/plots".format(os.path.realpath(os.path.dirname(__file__))))
	plt.savefig("{}/plots/day{}.png".format(os.path.realpath(os.path.dirname(__file__)), day), transparent=False, facecolor='white')
	plt.close()

	if len(population) == amounts[0]:
		virusDefeated = True

	return virusDefeated

def createGif(day):
	frames = []

	for i in range(day):
		frames.append(imageio.imread("/plots/day{}.png".format(i)))

	imageio.mimsave("{}/animation.gif".format(os.path.realpath(os.path.dirname(__file__))), frames, duration = day, loop = 1)

if __name__ == "__main__":
	MAX_DAYS = 50
	virusDefeated = False

	map = np.zeros(shape=(100, 100), dtype=int) # Simulation map
	population = [] # List of Person objects

	# Generate population of 100 people
	for i in range(100):
		population, map = generatePopulation(population, map)

	day = 0

	# Plotting day 0
	plotMap(population, map, day)
	day += 1

	# Simulation loop starting from day 1
	while (len(population) > 0 and day < MAX_DAYS and not virusDefeated):
		population = calculateState(population)
		population = calculateContact(population, map)
		population = calculateImmunity(population)
		population, map = calculateMove(population, map)
		population = incrementDaysInState(population)
		virusDefeated = plotMap(population, map, day)
		day += 1
		#print("BREATHING") # Just to know that the program is still running

	if virusDefeated:
		print("Wirus zostal pokonany po {} dniach. Populacja: {}".format(day, len(population)))
	else:
		print("Symulacja zakonczona po ", day, " dniach. Populacja:", len(population))

	createGif(day)