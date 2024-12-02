// index.js

// Get the DOM elements
const innerSquare = document.getElementById('inner-square');
const squareArea1 = document.getElementById('Square-area1');
const squareArea2 = document.getElementById('Square-area2');
const areaRatio = document.getElementById('area-ratio');
const increaseBtn = document.getElementById('increase-btn');
const decreaseBtn = document.getElementById('decrease-btn');

// Constants
const maxOuterSquareSide = 160; // Maximum side length of the outer square (starting at 160px, not exceeding this)
const step = 40; // The step by which the inner square changes
const minInnerSide = 40; // Minimum side length of the inner square
let innerSide = 40; // Initial side length of the inner square

// Function to update the square area and ratio
function updateInfo() {
    const outerArea = maxOuterSquareSide * maxOuterSquareSide;
    const innerArea = innerSide * innerSide;
    
    // Setting up the ratio according to the side length of the inner square
    let ratioFraction = '1/16';
    if (innerSide === 80) {
        ratioFraction = '1/4';
    } else if (innerSide === 120) {
        ratioFraction = '3/4';
    } else if (innerSide === 160) {
        ratioFraction = '1/1';
    }

    squareArea1.textContent = outerArea;
    squareArea2.textContent = innerArea;
    areaRatio.textContent = ratioFraction;
}

// Function to update the inner square size
function updateInnerSquareSize() {
    innerSquare.style.width = `${innerSide}px`;
    innerSquare.style.height = `${innerSide}px`;

    // Ensure the inner square stays aligned to the top-left corner
    innerSquare.style.top = '0';
    innerSquare.style.left = '0';

    updateInfo();
}

// Event listeners for the buttons
increaseBtn.addEventListener('click', () => {
    if (innerSide + step <= maxOuterSquareSide) {
        innerSide += step;
        updateInnerSquareSize();
    }
});

decreaseBtn.addEventListener('click', () => {
    if (innerSide - step >= minInnerSide) {
        innerSide -= step;
        updateInnerSquareSize();
    }
});

// Initial call to set up the square
updateInnerSquareSize();
