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
