import cv2
import sys

faceCascade = cv2.CascadeClassifier('/home/apoorva/Downloads/opencv-master/data/haarcascades/haarcascade_frontalface_alt2.xml')

choice=int(input("Enter (1) if you want an image to be processed, \nOR\n(2) if you want your web Camera to capture live video stream to detect faces"))

if choice==2:
    video_capture = cv2.VideoCapture(0)

    while True:
        ret, frame = video_capture.read()

        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        faces = faceCascade.detectMultiScale(gray,scaleFactor=1.1,minNeighbors=5,minSize=(30, 30),flags=cv2.CASCADE_SCALE_IMAGE)

        for (x, y, w, h) in faces:
            cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

        cv2.imshow('Video', frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    video_capture.release()

elif choice==1:
    imagePath=input("Enter image path:")
    image = cv2.imread(imagePath)
    print (image.shape)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

#print(face_cascade.empty())
#faces = faceCascade.detectMultiScale(gray,scaleFactor=1.1,minNeighbors=5,minSize=(30, 30),flags = cv2.CV_HAAR_SCALE_IMAGE)
#scaleFactor=1.2 and above until 1.35 is kinda good. best is 1.2
    faces = faceCascade.detectMultiScale(gray,scaleFactor=1.2,minNeighbors=5,minSize=(30, 30),flags =cv2.CASCADE_SCALE_IMAGE)
    print("Found "+format(len(faces))+" faces!")

    for (x, y, w, h) in faces:
        cv2.rectangle(image, (x, y), (x+w, y+h), (0, 255, 0), 2)
    cv2.imshow("Faces found", image)

else:
    cv2.destroyAllWindows()

cv2.waitKey(0)
cv2.destroyAllWindows()
