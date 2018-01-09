const debug = require('debug')('pws-robot:gui');
const express = require('express');
const http = require('http');
const io = require('socket.io');

// Size of the screen: 480 * 640

class GUI {
  constructor() {
    // Create websocket server
    this.app = express();
    this.http = http.Server(this.app);
    this.io = io(this.http);

    // HTTP requestion get served ./public
    this.app.use(express.static('public'));

    // Listen for incomming socket connections
    this.io.on('connection', (socket) => {
      debug('Client connected');

      // Send the current application state when browser connects
      socket.emit('stateUpdate', this.state);
    });

    this.http.listen(3000, () => {
      debug('Server started on *:3000');
    });

    // Initial state object. This object will be adited by `index.js` to
    // reflect the current aplication state.
    this.state = {
      address: null,
      information: null,
      color: 'white',
    };
  }

  // This function will be called by `index.js` when it has updated the state
  // object.
  broadcastState() {
    debug('Sending state to client', this.state);

    // Send the state to all connected browsers (should only be one).
    this.io.emit('stateUpdate', this.state, { for: 'everyone' });
  }
}

module.exports = GUI;
