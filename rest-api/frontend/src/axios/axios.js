import axios from "axios"
import { store } from "@/vuex"

const API = axios.create({ baseURL: "http://52.28.228.31:8000" })

API.defaults.headers.post["Content-Type"] = "application/json"
API.defaults.headers.patch["Content-Type"] = "application/json"
API.defaults.headers.put["Content-Type"] = "application/json"

API.interceptors.request.use(
    async request => {
        let token = store.state.userStore.token
        if (token) {
            request.headers.common["Authorization"] = `Bearer ${token}`
        }
        return request
    }
)

export const api = {
    install(Vue) {
        Vue.prototype.$api = API
    }
}