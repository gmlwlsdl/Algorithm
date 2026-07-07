const input = require('fs').readFileSync(0).toString().trim();

[...input].forEach(a => {
    console.log(a);
})