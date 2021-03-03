let number;
let operator;

let first  = 0;
let second = 0;

screen    = document.getElementById("numberOnScreen")
numbers   = document.getElementsByClassName("numberButton");
operators = document.getElementsByClassName("operatorButton");
clear     = document.getElementById("clearButton");
equal     = document.getElementById("equalButton");

Array.from(numbers).forEach(item => {
    item.addEventListener("click", _ => {
        number = parseInt(item.innerText);
        if (operator == undefined) {
            first = first * 10 + number;
            screen.textContent = first;
        }
        else {
            second = second * 10 + number; 
            screen.textContent = second;
        }
    });
});

Array.from(operators).forEach(item => {
    item.addEventListener("click", _ => {
        operator = item.innerText;
        screen.textContent = operator;
    });
});

clear.addEventListener("click", _ => {
    first  = 0;
    second = 0;
    screen.textContent = 0;
});

equal.addEventListener("click", _ => {
    if (operator != undefined)
    {
        if (operator == "+")
            result = first + second;
        else if (operator == "-")
            result = first - second;
        else if (operator == "*")
            result = first * second;
        else if (operator == "=")
            result = first = second;
        else
            result = first / second;
            
        screen.textContent = result;
        first = result;
        second = 0;
        operator = undefined;
    }
});