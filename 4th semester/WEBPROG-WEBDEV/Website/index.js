const myBox = document.getElementById("myBox");
const myButton = document.getElementById("myButton");

myButton.addEventListener("click",event =>{
    myBox.style.backgroundColor = "tomato";
    myBox.textContent = "OUCH! 😖"
});

myButton.addEventListener("mouseover", event =>{
    myBox.style.backgroundColor = "lightyellow";
    myBox.textContent = "DONT DO IT! 😲"
});

myButton.addEventListener("mouseout", event =>{
    myBox.style.backgroundColor = "lightgreen";
    myBox.textContent = "Click me  💚"
});
