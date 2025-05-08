MintrixWeb::Webpage testPage = {
  .page_html = R"=====(
  <!DOCTYPE html>
  <html>
    <head>
      <title>Mintrix</title>
      <meta charset='utf-8'>
      <link rel='shortcut icon' href='#'/>
      <link rel='stylesheet' type='text/css' href='/style.css'>
      <script type='text/javascript' src='/script.js'></script>
    </head>
    <body>
      <p>Ich habe einen kleine mîkroskopischen Penis </p>
    </body>
  </html
  )=====",
  
  .style_css = R"=====(
  body {
    background: #000000;
  }
  
  #ctls {
    display: grid;
    position: absolute;
    left: 50%;
    top: 50%;
    transform: translate(-50%, -50%);
    height: 80vh;
    width: 80vh;
    grid-template-columns: 4fr 3fr 4fr;
    grid-template-rows: 4fr 3fr 4fr;
    grid-gap: .7rem;
  }
  
  @media (orientation: portrait) {
    #ctls {
      height: 80vw;
      width: 80vw;
    }
  }
  
  button {
    border: .7rem solid #ffffff;
    border-radius: 7.5rem;
  }
  )=====",

  .script_js = "function clicked(name) {xhr = new XMLHttpRequest();xhr.open('POST', '/data/?btn=' + name);xhr.setRequestHeader('Content-Type', 'text/plain');xhr.send();}"
};
