const input = require('fs').readFileSync(0).toString().trim();
var answer = '';

for (i = 0; i < input.length; i++) {
    if (input[i].toUpperCase() === input[i]) {
        answer += input[i].toLowerCase();
        
    } else {
        answer += input[i].toUpperCase();
    }
}

console.log(answer);