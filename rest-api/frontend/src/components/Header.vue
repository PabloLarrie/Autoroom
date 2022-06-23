<template>
  <div id="header">
    <b-navbar toggleable="lg" style="width: 100%">
      <a class="navbar-header" href="/"><img src="@/assets/AR.jpg" alt=""></a>
    </b-navbar>
  </div>
</template>

<script>
export default {
  name: "MyHeader",
  data() {
    return {
      bg_color: '#2e2831'
    };
  },
};
</script>

<style scoped>
a, img {
  width: 28%;
  height: 18%;
  margin-left: 1%;
}
#header {
  background-color: black;
}
</style>