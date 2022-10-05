let weather= {
    apiKey: '89e8665ccbea04476b6dd1e50c6a80fc',
    fetchweather: function (city){
           fetch(`http://api.openweathermap.org/data/2.5/weather?q=${city}&units=metric&appid=89e8665ccbea04476b6dd1e50c6a80fc`)
           .then((response)=> response.json())
            .then((data) => this.displayWeather(data));
    },

    displayWeather: function(data){
         const {name} = data
         const { icon ,  description} = data.weather[0]

         const {temp, humidity} = data.main
         const {speed } = data.wind
        //  console.log(name, description,   icon, temp, humidity, speed);
        // console.log('icon = ', icon);
        let imgurl = `https://source.unsplash.com/1600x900/?${name}`
         document.querySelector('.city').innerHTML = `<h2> Weather in ${name} </h2> `
         document.querySelector('.temp').innerHTML = `<h1>${temp}ºC</h1>`
         document.querySelector('.weather-type').innerText = description
         document.querySelector('.icon').src = `https://openweathermap.org/img/wn/${icon}@2x.png`
         document.querySelector('.humid').innerText = 'Humidity: ' + humidity + '%'
         document.querySelector('.wind').innerText = 'Wind Speed: '+ speed + ' Kmph'
         document.querySelector('.weather').classList.remove('loading');
        //  document.body.style.backgroundImage = `url(${imgurl})`
        
         



    },
    search: function(){
        this.fetchweather(document.querySelector('.search-bar').value)
    }

    
}


 document.querySelector('.search-btn').addEventListener('click', function (){
    weather.search()
 })
//  Enter key event pending


