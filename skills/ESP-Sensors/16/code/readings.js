const Readline = require ("@serialport/parser-readline");
const SerialPort = require ("serialport");
const port = new SerialPort("COM4", {baudRate: 115200});

const parser = new Readline();
port.pipe(parser);

parser.on("data", (line) => console.log(`> ${line}`));
port.write("Power On\n");
