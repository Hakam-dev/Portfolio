const display = document.getElementById("display");
let degreeMode = true;

function appendValue(value){
    display.value += value;
}

function clearDisplay(){
    display.value = "";
}

function calculate(){

    try{
        display.value = eval(display.value);
    }

    catch{
        display.value = "Error";
    }

}
function deleteLast(){
        display.value = display.value.slice(0, -1);
    }
function squareRoot(){
    display.value =
    Math.sqrt(parseFloat(display.value));
}
function square(){
    let num =
    parseFloat(display.value);

    display.value =
    num * num;
}
function power(){
    appendValue("**");
}
function insertPi(){
    display.value += Math.PI;
}
function insertE(){
    display.value += Math.E;
}
function toggleMode(){

    degreeMode = !degreeMode;

    document.getElementById("modeBtn").innerText =
        degreeMode ? "Deg" : "Rad";
}
function sinValue(){

    let num = parseFloat(display.value);

    if(degreeMode){
        num = num * Math.PI / 180;
    }

    display.value = formatResult(Math.sin(num));
}
function cosValue(){

    let num = parseFloat(display.value);

    if(degreeMode){
        num = num * Math.PI / 180;
    }

    display.value = formatResult(Math.cos(num));
}
function tanValue(){

    let num = parseFloat(display.value);

    if(degreeMode){
        num = num * Math.PI / 180;
    }

    display.value = formatResult(Math.tan(num));
}
function logValue(){

    let num = parseFloat(display.value);

    display.value =
        formatResult(Math.log10(num));
}
function lnValue(){

    let num = parseFloat(display.value);

    display.value =
        formatResult(Math.log(num));
}
function formatResult(num){
    return parseFloat(num.toFixed(10));
}