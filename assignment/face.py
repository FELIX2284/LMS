import cv2
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades+'haarcascade_frontalface_default.xml')
start = r'C:\Users\felix\Desktop\assignment\WhatsApp Image 2024-06-05 at 09.26.25_87fcf3c0.jpg'                                   
img= cv2.imread(start)
grey = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
faces = face_cascade.detectMultiScale(grey, 1.1, 4)
for (x, y, w, h) in faces:
    cv2.rectangle(img, (x, y), (x + w, y + h), (255, 255,0), 5)
cv2.imshow('img', img)
cv2.waitKey(0)

from deepface import Deepface
pathimg=r'C:\Users\felix\Desktop\assignment\WhatsApp Image 2024-06-05 at 09.26.25_87fcf3c0.jpg'

result = Deepface.anlyze(pathimg, actions=['gender'])
gender = result ['gender']

print(f"Predicted gender is: {gender}") 
result=Deepface.analyze(pathimg, actions=['age'])
age = result ['age']
print(f"Predicted age is: {age} years")