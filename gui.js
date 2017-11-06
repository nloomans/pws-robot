const debug = require('debug')('pws-robot:gui');
const express = require('express');
const http = require('http');
const io = require('socket.io');

class GUI {
  constructor() {
    this.app = express();
    this.http = http.Server(this.app);
    this.io = io(this.http);

    this.app.use(express.static('public'));

    this.io.on('connection', (socket) => {
      debug('Client connected');
      socket.emit('stateUpdate', this.state);
    });

    this.http.listen(3000, () => {
      debug('Server started on *:3000');
    });

    this.state = {
      address: null,
      information: null,
      color: 'white',
    };
  }

  broadcastState() {
    debug('Sending state to client', this.state);
    this.io.emit('stateUpdate', this.state, { for: 'everyone' });
  }
}

module.exports = GUI;
