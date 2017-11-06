/* eslint no-shadow: "off" */

const debug = require('debug')('pws-robot:index');
const Web3 = require('web3');
const GUI = require('./gui');

if (typeof global.web3 !== 'undefined') {
  global.web3 = new Web3(global.web3.currentProvider);
} else {
  // set the provider you want from Web3.providers
  global.web3 = new Web3(new Web3.providers.HttpProvider('http://localhost:8545'));
}

const { web3 } = global;

// 480 * 640

const gui = new GUI();

debug('Requesting account data');

function waitForTransactionToAddress(recipientHash) {
  return new Promise((resolve, reject) => {
    const filter = web3.eth.filter('latest');
    filter.watch((err, blockHash) => {
      if (err) {
        reject(err);
        filter.stopWatching();
        return;
      }
      debug(`\x1b[1mBlock ${blockHash}\x1b[0m`);
      const block = web3.eth.getBlock(blockHash, true);
      const filteredTransactions = block.transactions.filter((transaction) => {
        const humanReadableValue = web3.fromWei(transaction.value, 'ether').toString()
        debug(`${transaction.hash} : ${transaction.from} -> ${humanReadableValue} ETHER -> ${transaction.to}`);
        return transaction.to === recipientHash;
      });

      if (filteredTransactions.length > 0) {
        resolve(filteredTransactions[0]);
        filter.stopWatching();
      }
    });
  });
}

gui.state.address = web3.toChecksumAddress('0x5bcd404e6b96dfd033bd362d0f947753d5fb1f57');
gui.state.information = 'Please send 0.2 ETHER';
gui.broadcastState();

waitForTransactionToAddress('0x5bcd404e6b96dfd033bd362d0f947753d5fb1f57').then((transaction) => {
  console.log(transaction);
  gui.state.address = null;
  gui.state.information = 'Thank you!';
  gui.state.color = 'green';
  gui.broadcastState();
});
