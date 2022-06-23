import '@babel/polyfill'
import 'mutationobserver-shim'
import Vue from 'vue'
import './plugins/bootstrap-vue'
import { router } from './router/router'
import App from './App.vue'
import VueRouter from "vue-router"

Vue.config.productionTip = false
Vue.use(VueRouter)

new Vue({
  router,
  render: h => h(App),
}).$mount('#app')

Vue.prototype.bg_color = '#2e2831'
