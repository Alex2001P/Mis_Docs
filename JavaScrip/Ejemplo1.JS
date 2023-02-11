/**Llamamos nuestra funcion local_Storage */
guardar_localstorage();
/** CREAMOS NUESTRA FUNCION */
function guardar_localstorage() {
    let persona = {
        /**Creamos nuestro objeto en este caso es nuestra
persona */
        nombre: "Agusto",
        apellido: "Fernandez",
        edad: 18,
        coords: {
            /**Estas son unas cordenadas para fallida */
            lat: 10,
            /** esta es nuestra latitud */
            lng: -10 /** esta es una longitud */
        }
    };
    let nombre = "Mario"; /** creamos otro objeto */
    localStorage.setItem("Nombre", nombre);
    /**esto es para poder grabar
nuestro local_storage*/
    localStorage.setItem("persona", persona);
}