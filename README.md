# pws-robot

Project structure:

```
pws-robot
├── gui.js (comunicate with index.html using a socket connection)
├── index.js (main file)
└── public (viewed in the browser)
    ├── index.html (communicate with gui.js using a socket connection)
    └── lib (client side libaries used)
        ├── qrcode.js (qr code)
        └── socket.io.js (socket connection)
```


```
Serial at 115200 speed.
The code is written for linux, it will not work on windows/macOS.
Give the arduino at least 2 seconds to respond to a Serial input.
Dependencies:
- PySerial https://pythonhosted.org/pyserial/

```
