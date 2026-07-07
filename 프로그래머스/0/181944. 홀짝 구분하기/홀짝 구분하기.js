const input = require('fs').readFileSync(0).toString().trim();

if (input % 2 === 0) console.log(input, 'is even');
else console.log(input, 'is odd');