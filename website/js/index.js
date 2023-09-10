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


// Code for sending 0 to the thingspeak field of the servo motor. 
document.getElementById("Off").addEventListener("click", turnOffServoMotor);

function turnOffServoMotor() {
    const channelID = "2266014";
    const apiKey = "T3V5SKT2D0768MCB";

    const data = {
        api_key: apiKey,
        field1: "1"
    };
    const apiUrl = `https://api.thingspeak.com/update.json?api_key=${data.api_key}&field1=0`;

    fetch(apiUrl, {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(data)
        })
        .then(response => {
            if (response.ok) {
                console.log("Servo motor turned off successfully");
            } else {
                console.error("Error sending data to ThingSpeak.");
            }
        })
        .catch(error => {
            console.error("An error occurred:", error);
        });
}