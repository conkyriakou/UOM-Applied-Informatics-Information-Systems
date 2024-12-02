// Track total pixels
let totalPixels = 10;

// Get references to DOM elements
const plusFive = document.getElementById('plusFive');
const minusFive = document.getElementById('minusFive');
const totalPixelsDisplay = document.getElementById('pixels');
const textDisplay = document.getElementById('textDisplay');

// Increment font size by 5px until it reaches 50px
plusFive.addEventListener('click', function () {
    if (totalPixels + 5 <= 50) { // Check if adding 5 will exceed 50
        totalPixels += 5;
        updateDisplay();
    }
});

// Decrement font size by 5px until it reaches 10px
minusFive.addEventListener('click', function () {
    if (totalPixels - 5 >= 10) { // Check if subtracting 5 will go below 10
        totalPixels -= 5;
        updateDisplay();
    }
});

// Update total pixels display and text font size
function updateDisplay() {
    totalPixelsDisplay.textContent = totalPixels; // Update pixel size display
    textDisplay.style.fontSize = totalPixels + 'px'; // Update font size
}
