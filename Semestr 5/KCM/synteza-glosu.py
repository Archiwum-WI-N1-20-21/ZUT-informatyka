import os
import speech_recognition as sr
from googletrans import Translator
import pyttsx3

def record():
	r = sr.Recognizer()
	r.energy_threshold = 300
	print("Rozpoznawanie...")
	with sr.Microphone() as source:
		audio = r.listen(source)

		try:
			recording = r.recognize_google(audio, language="pl-PL")
			print("Nagrana wiadomosc: " + recording)

		except Exception as e:
			print("Exception: " + str(e))

	return recording


def translate(input):
	translator = Translator()
	output = translator.translate(input, src="pl", dest="en")
	print("Przetlumaczona wiadomosc: " + output.text)
	return output.text

def synthesis(input_pl, input_en):
	converter = pyttsx3.init()
	converter.setProperty("rate", 150)
	converter.setProperty("volume", 0.7)

	converter.setProperty("voice", "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices\Tokens\TTS_MS_PL-PL_PAULINA_11.0")
	converter.say(input_pl)
	converter.runAndWait()

	converter.setProperty("voice", "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices\Tokens\TTS_MS_EN-US_ZIRA_11.0")
	converter.say(input_en)
	converter.runAndWait()


if __name__ == "__main__":
	recording = record()
	translatedRecording = translate(recording)
	synthesis(recording, translatedRecording)