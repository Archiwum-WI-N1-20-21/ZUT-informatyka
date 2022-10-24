import cv2 as cv
import numpy as np

img = cv.imread('hand.jpg')
hsvImg = cv.cvtColor(img, cv.COLOR_BGR2HSV)

minHSV = np.array([0, 0.18 * 255, 100], dtype="uint8")
maxHSV = np.array([180, 0.68 * 255, 255], dtype="uint8")

mask = cv.inRange(hsvImg, minHSV, maxHSV)
output_mask = cv.cvtColor(mask, cv.COLOR_GRAY2BGR)
output_image = cv.bitwise_and(img, img, mask=mask)

cv.imwrite('newhand.png',  np.hstack((img, output_mask, output_image)))