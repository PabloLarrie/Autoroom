<template>
  <general-layout>
    <template v-slot:generalBody>
      <b-form>

        <b-form-group label="Name:" >
          <b-form-input
              id="name"
              v-model="name"
              placeholder="Enter Deck Name"
              required
          ></b-form-input>
        </b-form-group>

        <b-button @click="submitDeck">Create</b-button>
      </b-form>
    </template>
  </general-layout>
</template>

<script>
import GeneralLayout from "@/layouts/GeneralLayout";
import axios from "axios";

export default {
  name: "Add",
  components: {
    GeneralLayout,
  },
  data() {
    return {
      name: '',
      selectedHero: null,
      standard: false,
      heroOptions: [],
      heroClass: '',
    }
  },
  methods: {
    submitDeck() {
      let values = {
            "name": this.name,
            "hero_class": this.selectedHero,
            "standard": this.standard,
        }
      this.$api.post("/decks/", values)
        console.log(values)
    },
  },
  mounted() {
    this.$api.get("/hero-classes/").then((response) => {
      this.heroOptions = response.data.results.reduce(
          (options, hero) => {
            options.push({ value: hero.id, text: hero.name });
            return options;
          },
          []
      )
      this.selectedHero = this.heroOptions[0].value
    });
  }
};
</script>
<style>
</style>