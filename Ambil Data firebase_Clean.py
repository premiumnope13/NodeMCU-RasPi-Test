import pyrebase
import time


config = {
  "apiKey": "",
  "authDomain": "t.com",
  "databaseURL": "",
  "projectId": "test-nodemcu-5ea41",
  "storageBucket": ""
}

firebase = pyrebase.initialize_app(config)

auth = firebase.auth() 
#authenticate a user
user = auth.sign_in_with_email_and_password("bm", "")

db = firebase.database()
user = auth.refresh(user['refreshToken'])
# now we have a fresh token
user['idToken']


while True:
    jarak = users = db.child("ULTRASONIC").get()
    print (jarak.val())
    time.sleep(0.1)
