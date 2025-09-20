<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Samsung Phone OS</title>
  <style>
    body {
      margin: 0;
      font-family: sans-serif;
      background-color: #000;
      color: #fff;
    }
    #screen {
      width: 360px;
      height: 640px;
      margin: 20px auto;
      border: 2px solid #333;
      border-radius: 20px;
      background-color: #111;
      overflow: hidden;
      position: relative;
    }
    .app {
      display: none;
      padding: 20px;
    }
    .home {
      display: block;
      text-align: center;
      padding-top: 60px;
    }
    .icon {
      display: inline-block;
      width: 80px;
      height: 80px;
      margin: 20px;
      background-color: #444;
      border-radius: 20px;
      line-height: 80px;
      font-size: 24px;
      cursor: pointer;
    }
    .back {
      position: absolute;
      top: 10px;
      left: 10px;
      background: #222;
      padding: 5px 10px;
      border-radius: 5px;
      cursor: pointer;
    }
    input, textarea {
      width: 100%;
      padding: 10px;
      margin-top: 10px;
      border: none;
      border-radius: 5px;
    }
    button {
      padding: 10px;
      margin-top: 10px;
      width: 100%;
      background-color: #555;
      color: white;
      border: none;
      border-radius: 5px;
      cursor: pointer;
    }
    video {
      width: 100%;
      border-radius: 10px;
      margin-top: 10px;
    }
  </style>
</head>
<body>
  <div id="screen">
    <div id="home" class="app home">
      <div class="icon" onclick="openApp('dialer')">📞</div>
      <div class="icon" onclick="openApp('messages')">💬</div>
      <div class="icon" onclick="openApp('settings')">⚙️</div>
      <div class="icon" onclick="openApp('camera')">📷</div>
      <div class="icon" onclick="openApp('calculator')">🧮</div>
    </div>

    <div id="dialer" class="app">
      <div class="back" onclick="goHome()">← Home</div>
      <h2>Dialer</h2>
      <input type="tel" id="phoneInput" placeholder="Enter number">
      <button onclick="dial()">Dial</button>
    </div>

    <div id="messages" class="app">
      <div class="back" onclick="goHome()">← Home</div>
      <h2>Messages</h2>
      <input type="text" id="msgTo" placeholder="To">
      <textarea id="msgBody" rows="4" placeholder="Your message"></textarea>
      <button onclick="sendMessage()">Send</button>
    </div>

    <div id="settings" class="app">
      <div class="back" onclick="goHome()">← Home</div>
      <h2>Settings</h2>
      <p>Fake OS v1.0</p>
      <p>Battery: 🔋 100%</p>
      <p>Wi-Fi: ✅ Connected</p>
    </div>

    <div id="camera" class="app">
      <div class="back" onclick="goHome()">← Home</div>
      <h2>Camera</h2>
      <video id="video" autoplay></video>
    </div>

    <div id="calculator" class="app">
      <div class="back" onclick="goHome()">← Home</div>
      <h2>Calculator</h2>
      <input type="text" id="calcInput" placeholder="e.g. 2+2">
      <button onclick="calculate()">Calculate</button>
      <p id="calcResult"></p>
    </div>
  </div>

  <script>
    function openApp(appId) {
      document.querySelectorAll('.app').forEach(app => app.style.display = 'none');
      document.getElementById(appId).style.display = 'block';
      if (appId === 'camera') startCamera();
    }

    function goHome() {
      document.querySelectorAll('.app').forEach(app => app.style.display = 'none');
      document.getElementById('home').style.display = 'block';
      stopCamera();
    }

    function dial() {
      const number = document.getElementById('phoneInput').value;
      alert(`Dialing ${number}...`);
    }

    function sendMessage() {
      const to = document.getElementById('msgTo').value;
      const body = document.getElementById('msgBody').value;
      alert(`Sending message to ${to}:\n${body}`);
    }

    function calculate() {
      const input = document.getElementById('calcInput').value;
      try {
        const result = eval(input);
        document.getElementById('calcResult').innerText = `Result: ${result}`;
      } catch {
        document.getElementById('calcResult').innerText = `Invalid expression`;
      }
    }

    let stream;
    function startCamera() {
      navigator.mediaDevices.getUserMedia({ video: true })
        .then(s => {
          stream = s;
          document.getElementById('video').srcObject = stream;
        });
    }

    function stopCamera() {
      if (stream) {
        stream.getTracks().forEach(track => track.stop());
        stream = null;
      }
    }
  </script>
</body>
</html>


