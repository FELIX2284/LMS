import cv2
import numpy as np
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades+'haarcascade_frontalface_default.xml')
start = r'C:\Users\felix\Desktop\assignment\WhatsApp Image 2024-06-08 at 18.39.30_e4cba11a.jpg'                                   
img= cv2.imread(start)
grey = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
faces = face_cascade.detectMultiScale(grey, 1.1, 4)
for (x, y, w, h) in faces:
    cv2.rectangle(img, (x, y), (x + w, y + h), (255, 255,0), 5)
cv2.imshow('img', img)



max_index = np.argmax(img[0])
emotions=("happy","angry","sad","neutral","suprise","disgust","fear")
predicted_emotion=emotions[max_index]

cv2.putText(img, predicted_emotion,(int(x),int(y)), cv2.FONT_HERSHEY_SIMPLEX,1,(0,0,255),2)

cv2.imshow("facial emotion analysis",img)
cv2.waitKey(0)

