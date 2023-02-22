/** AL HACERE CLICK EN BUTTON APARECE Y DESAPARECE CON TOGGLE 'ACTIVO' */
    const button = document.querySelector('button')
    const nav    = document.querySelector('nav')

    button.addEventListener('click',()=>{
        nav.classList.toggle('activo')
    })
