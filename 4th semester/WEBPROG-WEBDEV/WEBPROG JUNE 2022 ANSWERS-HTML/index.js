
window.onload = function(){ 
 const rec = document.getElementById("rectangle");
 var for1=0, for2=0;

document.getElementById("butt1").onclick = function() {Up_Down(rec)};
document.getElementById("butt2").onclick = function() {Left_Right(rec)};


function Up_Down(rec) {
    if (for1==0){
  rec.style.borderTop="0";
  rec.style.borderBottom="0";
  for1=1;
    }else {
        rec.style.borderTop="thick solid black";
        rec.style.borderBottom="thick solid black";
        for1=0;
    }
}

function Left_Right(rec) {
    if (for2==0){
  rec.style.borderLeft="0";
  rec.style.borderRight="0";
  for2=1;
    }else {
        rec.style.borderLeft="thick solid black";
        rec.style.borderRight="thick solid black";
        for2=0;
    }
}

}