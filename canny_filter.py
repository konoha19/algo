import cv2
import sys
import matplotlib.pyplot as plt
import time

video_capture = cv2.VideoCapture(0)
while True:
	ret, frame = video_capture.read()
	edges = cv2.Canny(frame,80,290)
	cv2.imshow('Video', edges)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break
video_capture.release()
