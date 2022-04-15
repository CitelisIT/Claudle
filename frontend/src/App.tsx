import React from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import HomePage from "./pages/HomePage";
import ProfilePage from "./pages/ProfilePage";
import RegisterPage from "./pages/RegisterPage";
import StatsPage from "./pages/StatsPage";

export default function App() {
  return (
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
  );
}
