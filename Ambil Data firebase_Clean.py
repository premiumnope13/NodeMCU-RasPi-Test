import pyrebase
import time
print ("Hello World")

config = {
  "apiKey": "AIzaSyBsrnOhng4Zp3dYcraVtx_eM8vKN9lIhDs",
  "authDomain": "test-nodemcu-5ea41.firebaseapp.com",
  "databaseURL": "https://test-nodemcu-5ea41.firebaseio.com",
  "projectId": "test-nodemcu-5ea41",
  "storageBucket": ""
}

firebase = pyrebase.initialize_app(config)

auth = firebase.auth() 
#authenticate a user
user = auth.sign_in_with_email_and_password("budi.aulian.h@gmail.com", "Gjwzjbsajkrf1234")

db = firebase.database()
user = auth.refresh(user['refreshToken'])
# now we have a fresh token
user['idToken']


while True:
    jarak = users = db.child("ULTRASONIC").get()
    print (jarak.val())
    time.sleep(0.1)