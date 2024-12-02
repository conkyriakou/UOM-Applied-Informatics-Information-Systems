// Initialize starting size and size range
let boxSize = 100; // Initial size in pixels
const minSize = 100;
const maxSize = 200;

// Get references to DOM elements
const plusTen = document.getElementById('plusTen');
const minusTen = document.getElementById('minusTen');
const box = document.getElementById('box'); // The box whose size you want to change
const size = document.getElementById('size'); // For showing current size

// Update box size and limit between 100px and 200px
function updateBoxSize(amount) {
    boxSize += amount;
    
    // Ensure size stays within limits
    if (boxSize < minSize) boxSize = minSize;
    if (boxSize > maxSize) boxSize = maxSize;
    
    // Apply the new size to the box
    box.style.width = boxSize + 'px';
    box.style.height = boxSize + 'px';
    
    // Update the size display
    size.textContent = boxSize; // Update the size in the display
}

// Handle button clicks
plusTen.addEventListener('click', function() {
    updateBoxSize(10);
});

minusTen.addEventListener('click', function() {
    updateBoxSize(-10);
});

// Initial size display
size.textContent = boxSize;
