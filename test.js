const { spawn } = require('child_process');

let ardiono = spawn('python', ['./RobotFiles/arduino.py', 'A']);
ardiono.on('close', (code) => {
  console.log('start exit code:', code);
  setTimeout(() => {
    ardiono = spawn('python', ['./RobotFiles/arduino.py', 'Z']);
    ardiono.on('close', (code) => {
      console.log('stop exit code:', code);
      ardiono = spawn('python', ['./RobotFiles/arduino.py', 'N']);
      ardiono.on('close', (code) => {
        console.log('dance exit code:', code);
        setTimeout(() => {
          ardiono = spawn('python', ['./RobotFiles/arduino.py', 'Z']);
          ardiono.on('close', (code) => {
            console.log('stop exit code:', code);
          });
        }, 2000);
      });
    });
  }, 6000);
});
