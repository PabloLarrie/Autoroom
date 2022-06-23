<template>
  <main-layout>
    <template v-slot:header>
      <my-header />
    </template>

    <template v-slot:body>
      <router-view />
    </template>
  </main-layout>
</template>

<script>
import MainLayout from "@/layouts/MainLayout";
import MyHeader from "@/components/Header";

export default {
  name: 'App',
  components: {
    MainLayout,
    MyHeader,
  },
}



</script>

<style>


</style>