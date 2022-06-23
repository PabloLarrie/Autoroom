<template>
  <general-layout>
    <template v-slot:generalBody>
      <b-table
        class="w-100"
        striped
        hover
        fixed
        noCollapse
        :items="items"
        :fields="columns"
        bordered
      >
      </b-table>
    </template>
  </general-layout>
</template>

<script>
import GeneralLayout from "@/layouts/GeneralLayout";
import axios from "axios";

export default {
  name: "EventsList",
  components: {
    GeneralLayout,
  },

  data() {
    return {
      items: [],
      online_status: "all",
      columns: [
        "room_id",
        "room_name",
        "temperature",
        "humidity",
        "time",
      ],
    };
  },
  mounted() {
    axios
      .get("http://localhost:8000/measures/")
      .then(response => (this.items = response.data))
   },
};
</script>
<style scooped>

* {
  margin:0;
  padding: 0;
  box-sizing: border-box;
}

</style>