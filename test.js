const { spawn } = require('child_process');

let ardiono = spawn('python', ['./RobotFiles/arduino.py', 'A']);
ardiono.on('close', (code) => {
  console.log('start exit code:', code);
  setTimeout(() => {
    ardiono = spawn('python', ['./RobotFiles/arduino.py', 'Z']);
    ardiono.on('close', (code_) => {
      console.log('stop exit code:', code_);
    });
  }, 5000);
});
