/* eslint no-shadow: "off" */

const debug = require('debug')('pws-robot:index');
const Web3 = require('web3');
const GUI = require('./gui');

const { spawn } = require('child_process');

if (typeof global.web3 !== 'undefined') {
  // This should never happend, but we keep it anyway juuuust to be sure.
  global.web3 = new Web3(global.web3.currentProvider);
} else {
  // set the provider you want from Web3.providers
  global.web3 = new Web3(new Web3.providers.HttpProvider('http://localhost:8545'));
}

const { web3 } = global;

// The GUI class allows us to easily put information on the screen from the
// backend.
const gui = new GUI();

debug('Requesting account data');

function waitForTransactionToAddress(recipientHash) {
  return new Promise((resolve, reject) => {
    // Listen for incomming blocks.
    const filter = web3.eth.filter('latest');
    filter.watch((err, blockHash) => {
      // New block created
      if (err) {
        reject(err);
        filter.stopWatching();
        return;
      }

      // Some fancy debugging
      debug(`\x1b[1mBlock ${blockHash}\x1b[0m`);
      const block = web3.eth.getBlock(blockHash, true);

      // Check if there are transactions that have `recipientHash` as recipient
      const filteredTransactions = block.transactions.filter((transaction) => {
        // Some fancy debugging
        const humanReadableValue = web3.fromWei(transaction.value, 'ether').toString();
        debug(`${transaction.hash} : ${transaction.from} -> ${humanReadableValue} ETHER -> ${transaction.to}`);
        return transaction.to === recipientHash;
      });

      // Check the result of that.
      if (filteredTransactions.length > 0) {
        // TODO: Check if the amount of ETHER was the expected amount.
        resolve(filteredTransactions[0]);
        filter.stopWatching();
      }
    });
  });
}

// Update the GUI
gui.state.address = web3.toChecksumAddress('0x5bcd404e6b96dfd033bd362d0f947753d5fb1f57');
gui.state.information = 'Please send 0.2 ETHER';
gui.broadcastState();

// Wait for a transaction to our address.
waitForTransactionToAddress('0x5bcd404e6b96dfd033bd362d0f947753d5fb1f57').then((transaction) => {
  console.log(transaction);

  // Update the GUI to say 'Thank you!'
  gui.state.address = null;
  gui.state.information = 'Thank you!';
  gui.state.color = 'green';
  gui.broadcastState();

  const ardiono = spawn('python3', ['./RobotFiles/arduino.py', 'startLine']);
  ardiono.on('close', (code) => {
    console.log('exit code:', code);
  });
});

// TODO: Automaticly restart the entire process.
