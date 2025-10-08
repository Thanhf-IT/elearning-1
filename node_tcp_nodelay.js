// node_tcp_nodelay.js
// node node_tcp_nodelay.js
const net = require('net');
const client = new net.Socket();
client.connect(9000, '127.0.0.1', () => {
  client.setNoDelay(true);
  console.log('Connected and TCP_NODELAY enabled');
  client.write('hello from node\n');
  setTimeout(() => client.end(), 500);
});
