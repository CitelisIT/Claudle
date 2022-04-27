import React, { createContext, useState } from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import HomePage from "./pages/HomePage";
import ProfilePage from "./pages/ProfilePage";
import RegisterPage from "./pages/RegisterPage";
import StatsPage from "./pages/StatsPage";

export interface SettingsContextInterface {
  lang: string;
  setLang: React.Dispatch<React.SetStateAction<string>>;
  layout: string;
  setLayout: React.Dispatch<React.SetStateAction<string>>;
  size: number;
  setSize: React.Dispatch<React.SetStateAction<number>>;
  tries: number;
  setTries: React.Dispatch<React.SetStateAction<number>>;
  hardMode: boolean;
  setHardMode: React.Dispatch<React.SetStateAction<boolean>>;
  gameState: number;
  setGameState: React.Dispatch<React.SetStateAction<number>>;
}

export const SettingsContext = createContext<SettingsContextInterface>(
  undefined!
);

export default function App() {
  const [lang, setLang] = useState("francais");
  const [layout, setLayout] = useState<string>("qwerty");
  const [size, setSize] = useState<number>(5);
  const [tries, setTries] = useState<number>(6);
  const [hardMode, setHardMode] = useState<boolean>(false);
  const [gameState, setGameState] = useState<number>(0);
  const value = {
    lang,
    setLang,
    layout,
    setLayout,
    size,
    setSize,
    tries,
    setTries,
    hardMode,
    setHardMode,
    gameState,
    setGameState,
  };
  return (
    <SettingsContext.Provider value={value}>
      <Router>
        <div className="app-wrapper">
          <Routes>
            <Route path="" element={<HomePage />} />
            <Route path="profile" element={<ProfilePage />} />
            <Route path="/register" element={<RegisterPage />} />
            <Route path="/stats" element={<StatsPage />} />
          </Routes>
        </div>
      </Router>
    </SettingsContext.Provider>
  );
}
