let username = "pol2";
let apiKey = "x";

const IO = new AdafruitIO(username, apiKey);

let colorPicker = document.querySelector("#colorInput");
let button = document.querySelector("#colorButton");

button.addEventListener("click", function(){
    let newColor = colorPicker.value;
    console.log(newColor);
    IO.postData("exercice", newColor);

})
