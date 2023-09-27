// Code for sending 1 to the thingspeak field of the servo motor 
document.getElementById("On").addEventListener("click", turnOnServoMotor);

function turnOnServoMotor() {
    const channelID = "2266014";
    const apiKey = "T3V5SKT2D0768MCB";

    const data = {
        api_key: apiKey,
        field1: "1"
    };
    const apiUrl = `https://api.thingspeak.com/update.json?api_key=${data.api_key}&field1=1`;

    fetch(apiUrl, {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(data)
        })
        .then(response => {
            if (response.ok) {
                console.log("Servo motor turned on successfully");
            } else {
                console.error("Error sending data to ThingSpeak.");
            }
        })
        .catch(error => {
            console.error("An error occurred:", error);
        });
}


// Code for sending 0 to the thingspeak field of the servo motor.  present no need will implement later.
// document.getElementById("Off").addEventListener("click", turnOffServoMotor);

// function turnOffServoMotor() {
//     const channelID = "2266014";
//     const apiKey = "T3V5SKT2D0768MCB";

//     const data = {
//         api_key: apiKey,
//         field1: "1"
//     };
//     const apiUrl = `https://api.thingspeak.com/update.json?api_key=${data.api_key}&field1=0`;

//     fetch(apiUrl, {
//             method: "POST",
//             headers: {
//                 "Content-Type": "application/json"
//             },
//             body: JSON.stringify(data)
//         })
//         .then(response => {
//             if (response.ok) {
//                 console.log("Servo motor turned off successfully");
//             } else {
//                 console.error("Error sending data to ThingSpeak.");
//             }
//         })
//         .catch(error => {
//             console.error("An error occurred:", error);
//         });
// }
var p=document.getElementById("Ph");
var r=p.textContent;
console.log(r)
let q=Number(r)
console.log(q)
if(q<6){
    p.style.backgroundColor="red"
    alert("Change water! It became acidic")
}
else if(q>8){
    p.style.backgroundColor="blue"
    alert("Change water! It became basic")
}

var p1=document.getElementById("Turb");
var r1=p1.textContent;
console.log(r1)
let q1=Number(r1)
console.log(q1)
if(q1>50){
    p1.style.backgroundColor="blue"
    alert("Water became impure. Please change it")
}

var p2=document.getElementById("Temp");
var r2=p2.textContent;
console.log(r2)
let q2=Number(r2)
console.log(q2)
if(q2<10 || q2>40){
    p2.style.backgroundColor="blue"
    alert("Temperature is not suitable for life. Please change water")
}