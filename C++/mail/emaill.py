import csv, smtplib
from email.message import EmailMessage
server =smtplib.SMTP('smtp.gmail.com',587)
server.starttls()
server.login('roboticsclub@iiitsurat.ac.in','atfmdxsurnjozoeo')
subject="📢 INVITATION TO ROBOTICS EVENTS AT SPRING FIESTA 2K25 – IIIT SURAT"
msg='''Dear Administration ,

Greetings from MARC Robotics Club, IIIT Surat!

We are thrilled to invite your college to participate in our Robotics Events under Spring Fiesta 2K25, happening on 10th, 11th, and 12th April 2025 at IIIT Surat.

🔥 Event Schedule:
📅 10th April – Robo Sumo 🏆 (Test your bot’s strength in the ultimate sumo battle!)
📅 11th April – Robo Soccer ⚽ (Compete in a thrilling robotic soccer match!)
📅 12th April – Line Follower 🚗 (Showcase your autonomous robot’s precision and speed!)
📅 12th April – Circuit Jam ⚡ (A competitive circuit design challenge for innovators!)

This is a fantastic opportunity to compete, network, and win exciting prizes while showcasing your technical skills in robotics and circuit design.

📌 Register Now!
🔗 Robo Sumo: https://bit.ly/43WKigF
🔗 Robo Soccer: https://bit.ly/4j0JLP1
🔗 Circuit Jam: https://bit.ly/41J0gcU
🔗 Line Follower: https://bit.ly/43WbWdC

For any queries, feel free to reach out to Jugal Patel (Lead, MARC Robotics Club) – 8866172036.

We look forward to your enthusiastic participation!

Best Regards,
MARC Robotics Club
IIIT Surat
📩 roboticsclub@iiitsurat.ac.in'''
sender='roboticsclub@iiitsurat.ac.in'

with open(r"D:\coadings\mail\emaill.csv") as file:
    reader=csv.reader(file)
    next(reader)
    for name,addr in reader:
        email=EmailMessage()
        email['From']=sender
        email['To']=addr
        email['Subject']=subject
        email.set_content(msg)
        server.send_message(email)
        print(f'Sent to {name}\n')
server.close()