import VueRouter from "vue-router"
import EventsList from "@/components/Main";


export const router = new VueRouter({
    mode: "history",
    routes: [
        {
            path: "/",
            name: "",
            component: EventsList,
        },
    ],
})
