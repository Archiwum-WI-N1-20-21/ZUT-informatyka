const ctx = document.getElementById('myChart').getContext('2d');

var graphData = {
  type: 'line',
  data: {
    labels: [],
    datasets: [{
      label: 'My First dataset',
      backgroundColor: 'rgb(255, 99, 132)',
      borderColor: 'rgb(255, 99, 132)',
      data: [12, 19, 3, 5, 2, 3],
    }]
  },
  options: {}
}

var myChart = new Chart(ctx, graphData);

console.log("penis");

var socket = new WebSocket("ws://localhost:8000/ws/graph/");

console.log("kutang");

socket.onmessage = function (e) {
  var djangoData = JSON.parse(e.data);
  console.log(djangoData);

  var newGraphData = graphData.data.datasets[0].data;
  newGraphData.shift();
  newGraphData.push(djangoData.value);
  graphData.data.datasets[0].data = newGraphData;
  myChart.update();

  document.querySelector("#app").innerText = djangoData.value;
};