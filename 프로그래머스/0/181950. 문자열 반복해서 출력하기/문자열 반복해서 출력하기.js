const [str, n] = require('fs').readFileSync(0).toString().trim().split(' ');

console.log(str.repeat(n));