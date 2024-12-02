//DICE ROLLER PROGRAM

function rollDice() {
    const numOfDice = document.getElementById("numOfDice").value;
    const diceResult = document.getElementById("diceResults");
    const diceImages = document.getElementById("diceImages"); // Corrected this line
    const values = [];
    const images = [];

    for (let i = 0; i < numOfDice; i++) {
        const value = Math.floor(Math.random() * 6) + 1;
        values.push(value);
        images.push(`<img src="dice_images/${value}.png" alt="Dice ${value}">`);
        console.log(`Image path: dice_images/${value}.png`);
    }

    diceResult.textContent = `Dice: ${values.join(' , ')}`;
    diceImages.innerHTML = images.join('');
}
