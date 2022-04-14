import React, { useState } from "react";
import { CogIcon, UserIcon, ChartBarIcon } from "@heroicons/react/outline";
import Settings from "./Settings";
import InfoPopup from "./InfoPopup";
import Sidebar from "./Sidebar";
import { Link } from "react-router-dom";
import LoginPopup from "./LoginPopup";

export default function Navbar() {
  const [settingsOpen, setSettingsOpen] = useState<boolean>(false);
  const [loginOpen, setLoginOpen] = useState<boolean>(false);

  return (
    <>
      <Settings settingsOpen={settingsOpen} setSettingsOpen={setSettingsOpen} />
      <LoginPopup loginOpen={loginOpen} setLoginOpen={setLoginOpen} />
      <nav className="flex items-center justify-between h-12 p-2 border-b md:h-16 md:p-4 bg-grey-900 border-grey-600">
        <div className="flex items-center justify-start w-20 gap-2 md:w-32 md:gap-4">
          <Sidebar />
          <InfoPopup />
        </div>
        <Link to="/" className="text-2xl font-bold text-gray-200">
          WORDLE
        </Link>
        <div className="flex items-center justify-center gap-2 md:gap-4">
          <Link to="/stats">
            <ChartBarIcon className="w-6 h-6 text-gray-200 md:w-8 md:h-8" />
          </Link>
          <button onClick={() => setLoginOpen(true)}>
            <UserIcon className="w-6 h-6 text-gray-200 md:w-8 md:h-8" />
          </button>
          <button onClick={() => setSettingsOpen(true)}>
            <CogIcon className="w-6 h-6 text-gray-200 md:w-8 md:h-8" />
          </button>
        </div>
      </nav>
    </>
  );
}
