
function showtime(){

    // Date class give hrs, min and sec

let date = new Date();
let display_time_here = document.querySelector('#display_time_here');

let hours = date.getHours();
let minutes  = date.getMinutes();
let seconds  = date.getSeconds();

let session = "am";
// for 12 - hr format

if(hours > 12)
{
    hours = hours - 12;
    session = "pm";
}
// at 12 hours will be 0 so to avoid 0 set hours = 12


if(hours == 0){
        hours= 12;
}

// to add trailing zeroes

hours = ( hours < 10) ? '0' + hours : hours; 
minutes = ( minutes < 10) ?'0'+ minutes : minutes; 
seconds = ( seconds < 10) ? '0' + seconds : seconds; 

let time = hours + ":" + minutes + ":" + seconds + " " + session;


    display_time_here.innerText = time;
    setTimeout(showtime,  1000);

}

    showtime();
