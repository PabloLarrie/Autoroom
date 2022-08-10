<template>
  <div id="app" class="container">
    <div class="col text-center mt-lg-5">
      <h1>Main Room</h1>
      <Bar
        :chart-options="chartOptions"
        :chart-data="measureData"
        :height="height"
      />
    </div>
    <div class="col text-center mt-lg-5">
      <h1>Room de Mich</h1>
      <Bar
        :chart-options="chartOptions"
        :chart-data="measureData2"
        :height="height"
      />
    </div>
    <div class="col text-center mt-lg-5">
      <h1>WC Room</h1>
      <Bar
        :chart-options="chartOptions"
        :chart-data="measureData3"
          :height="height"
      />
    </div>
  </div>

</template>

<script>
import axios from "axios";
import { Bar } from 'vue-chartjs/legacy';
import {
  Chart as ChartJS,
  Title,
  Tooltip,
  Legend,
  BarElement,
  PointElement,
  CategoryScale,
  LinearScale,
  LineElement,
  LineController,
 } from 'chart.js'

ChartJS.register(Title, Tooltip, Legend, BarElement, CategoryScale, LinearScale, LineElement, PointElement, LineController)

export default {
  name: "App",
  components: {
    Bar,
  },
props: {
    height: {
      type: Number,
      default: 500
    },
  },
  data() {
    return {
      measureData: {
        labels: [],
        datasets: [{
          backgroundColor: 'rgba(255, 99, 132, 0.2)',
          label: 'Temperature',
          data: [] },
        {
          backgroundColor: "turquoise",
          type: 'line',
          fill: false,
          label: 'Humidity',
          data: [],
      }
        ],
      },
      measureData2: {
        labels: [],
        datasets: [{
          backgroundColor: 'rgba(255, 99, 132, 0.2)',
          label: 'Temperature',
          data: [] },
        {
          backgroundColor: "turquoise",
          type: 'line',
          fill: false,
          label: 'Humidity',
          data: [],
      }
        ],
      },
      measureData3: {
        labels: [],
        datasets: [{
          backgroundColor: 'rgba(255, 99, 132, 0.2)',
          label: 'Temperature',
          data: [] },
        {
          backgroundColor: "turquoise",
          type: 'line',
          fill: false,
          label: 'Humidity',
          data: [],
      }
        ],
      },

      times: [],
      config: {
        type: 'scatter',
        data: this.measureData,
        options: {
          scales: {
            y: {
              beginAtZero: true
            }
          }
        }
      },
      chartOptions: {
        responsive: true,
        maintainAspectRatio: false
      }
    };
  },
  async created() {
    const {data} = await axios.get("http://localhost:8000/measures/");
    data.forEach(d => {
      const {
        room_id,
        temperature,
        humidity,
        time,
      } = d;
      if (room_id === 1 ) {
        this.measureData.labels.push(time);
        this.measureData.datasets[0].data.push(temperature);
        this.measureData.datasets[1].data.push(humidity);
      } else if (room_id === 2) {
        this.measureData2.labels.push(time);
        this.measureData2.datasets[0].data.push(temperature);
        this.measureData2.datasets[1].data.push(humidity);
      } else {
        this.measureData3.labels.push(time);
        this.measureData3.datasets[0].data.push(temperature);
        this.measureData3.datasets[1].data.push(humidity);
      }


    })
  }
}
</script>
<style>

</style>