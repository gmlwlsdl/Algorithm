const [a, b] = require('fs').readFileSync(0).toString().trim().split(' ');

console.log('a = '+a);
console.log('b = '+b);