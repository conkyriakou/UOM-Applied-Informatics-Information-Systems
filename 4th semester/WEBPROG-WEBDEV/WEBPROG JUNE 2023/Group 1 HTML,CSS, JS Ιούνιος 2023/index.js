function parse_elements(x){
    return document.querySelector(x)
  }
  
  function button_events(button, direction){
    return button.addEventListener('click', function(){
      let temp = document.querySelector('#myBox').style;
      let temp_direction = "border"+direction+"Radius";
  
      if (temp[temp_direction] !== '40px'){
        temp[temp_direction] = '40px';
      }
      else{
        temp[temp_direction] = '0px';
      }
    }, false);
  }
  
  let but1 = parse_elements('#UpRight');
  let but2 = parse_elements('#DownRight');
  let but3 = parse_elements('#UpLeft');
  let but4 = parse_elements('#DownLeft');
  
  but1 = button_events(but1, 'TopRight');
  but2 = button_events(but2, 'BottomRight');
  but3 = button_events(but3, 'TopLeft');
  but4 = button_events(but4, 'BottomLeft');





