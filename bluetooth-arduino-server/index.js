var express = require('express');
var SerialPort = require('serialport');

var app = express();
var arduino = new SerialPort('/dev/tty.linvor-DevB', {
  baudRate: 9600
});

arduino.on('error', function(err) {
  console.log('Error: ', err.message);
});

arduino.on('data', function (data) {
  console.log('Data: ' + data);
});

app.get('/led', function(req, res) {
    var name = req.query.name;
    var position = req.query.switch;
    
    if(name === 'switchgreen'){
        if(position === 'true'){
            arduino.write('5');
        }else {
            arduino.write('4');
        }
    } else if(name ==='switchorange'){
        if(position === 'true'){
            arduino.write('3');
        }else {
            arduino.write('2');
        }
    } else if(name==='switchred'){
        if(position === 'true'){
            arduino.write('1');
        }else {
            arduino.write('0');
        }
    }
    
    
    // Website you wish to allow to connect
    res.setHeader('Access-Control-Allow-Origin', 'http://localhost:8080');

    // Request methods you wish to allow
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');

    // Request headers you wish to allow
    res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,content-type');

    res.setHeader('Content-Type', 'text/plain');
    res.end('name : '+name+' / position : '+position);
});

app.get('/motor', function(req, res) {
    var name = req.query.name;
    var position = req.query.switch;
    
     if(name === 'servo1'){
        if(position === 'true'){
            arduino.write('7');
        }else {
            arduino.write('6');
        }
    }
    
    // Website you wish to allow to connect
    res.setHeader('Access-Control-Allow-Origin', 'http://localhost:8080');

    // Request methods you wish to allow
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');

    // Request headers you wish to allow
    res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,content-type');

    res.setHeader('Content-Type', 'text/plain');
    res.end('name : '+name+' / position : '+position);
});

app.listen(9999);