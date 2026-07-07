const [a, b] = require('fs').readFileSync(0).toString().trim().split(" ");
const sum = Number(a) + Number(b);
console.log(a,'+',b,'=',sum);